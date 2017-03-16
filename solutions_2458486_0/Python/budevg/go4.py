import pprint

def read_next_treasure():
    keys_num, chests_num = [int(e) for e in raw_input().split()][:2]

    keys_list = [int(e) for e in raw_input().split()][:keys_num]
    keys = {}
    for key in keys_list:
        keys[key] = keys.get(key, 0) + 1

    chests = []
    for i in range(chests_num):
        vals = [int(e) for e in raw_input().split()]
        open_key, inside_keys_num = vals[:2]
        inside_keys_list = vals[2:2+inside_keys_num]
        inside_keys = {}
        for key in inside_keys_list:
            inside_keys[key] = inside_keys.get(key, 0) + 1
        chests.append(dict(index = i + 1, type = open_key, keys = inside_keys))

    return (keys, chests)

def sanity_check(keys, chests):
    all_keys = keys.copy()
    all_types = {}

    for chest in chests:
        for key in chest["keys"]:
            all_keys[key] = all_keys.get(key, 0) + chest["keys"][key]
        all_types[chest["type"]] = all_types.get(chest["type"], 0) + 1

    # need to have key for every chest
    for t in all_types:
        if all_keys.get(t, 0) < all_types[t]:
            return False

    # can't have key to chest inside the same chest
    for chest in chests:
        t = chest["type"]
        if all_keys[t] == 1 and t in chest["keys"]:
            return False

    return True

def solve_treasure(keys, chests):
    #pprint.pprint(keys)
    #pprint.pprint(chests)
    #print chests
    if len(keys) == 0:
        return None

    if not sanity_check(keys, chests):
        return None

    if len(chests) == 1:
        for key in keys:
            if chests[0]["type"] == key:
                return [chests[0]["index"]]
        return None

    # try open one box and solve recursively
    for chest_index,chest in enumerate(chests):
        #if (len(chests) > 12):
        #    print "%d/%d" % (chest_index, len(chests))
        chest_type = chest["type"]
        if chest_type not in keys:
            continue

        rest_keys = keys.copy()
        if rest_keys[chest_type] > 1:
            rest_keys[chest_type] = rest_keys[chest_type] - 1
        else:
            del rest_keys[chest_type]
        for key in chest["keys"]:
            rest_keys[key] = rest_keys.get(key, 0) + chest["keys"][key]

        rest_chests = chests[:chest_index] + chests[chest_index+1:]
        solution = solve_treasure(rest_keys,
                                  rest_chests)
        if solution:
            return [chest["index"]] + solution
    return None

def main():
    num_of_cases = int(raw_input())
    for i in range(num_of_cases):
        keys, chests = read_next_treasure()
        #print i
        #pprint.pprint(keys)
        #pprint.pprint(chests)
        sequence = solve_treasure(keys, chests)
        if sequence is None:
            print "Case #%d: IMPOSSIBLE" % (i+1,)
        else:
            print "Case #%d: %s" % (i+1, " ".join(str(e) for e in sequence))

if __name__ == '__main__':
    main()
