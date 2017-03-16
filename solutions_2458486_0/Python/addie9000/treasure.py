#!/usr/local/bin/python
import sys, string


def do_we_have_hope(keys, chest_keys, chest_keyholes):
    k = keys[:]
    map(k.extend, chest_keys)
    for keyhole in chest_keyholes:
        if keyhole in k:
            k.remove(keyhole)
        else:
            return False
    return True


# open chest
# scan graph. but this implementation is super ugly... should be fixed soon.
def open_chest(keys, chest_keyholes, chest_keys, chests, open_stack, num):
    if not do_we_have_hope(keys, chest_keys, chest_keyholes):
        return []

    for i, keyhole in enumerate(chest_keyholes):
        if keyhole in keys:
            tmp_chest_keys = chest_keys[:]
            tmp_chests = chests[:]
            tmp_keys = keys[:]
            tmp_keyholes = chest_keyholes[:]
            tmp_open = open_stack[:]
            tmp_keyholes.pop(i)
            tmp_keys.remove(keyhole)
            tmp_keys.extend(tmp_chest_keys.pop(i))
            tmp_open.append(tmp_chests.pop(i))
            if len(tmp_open) == num:
                return tmp_open
            else:
                opened = open_chest(tmp_keys, tmp_keyholes, tmp_chest_keys, tmp_chests, tmp_open, num)
                if len(opened) == 0:
                    continue
                else:
                    return opened
    return []


#solve case function
def solve_case(keys, chests, case_number):
    chest_keyholes = []
    chest_keys = []
    zipped_chest = zip(range(1, len(chests) + 1), chests)
    zipped_chest.sort(reverse=True, key=lambda t: len(t[1]))
    for idx, chest in zipped_chest:
        chest_keyholes.append(chest[0])
        if chest[1] > 0:
            chest_keys.append(chest[2:])
        else:
            # no keys in the chest
            chest_keys.append([])

    opened = open_chest(keys, chest_keyholes, chest_keys, list(zip(*zipped_chest)[0]), [], len(chests))
    if len(opened) == 0:
        print "Case #%d: IMPOSSIBLE" % case_number
    else:
        print "Case #%d: %s" % (case_number, " ".join(map(str, opened)))


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = map(int, r.readline().strip().split(' '))[1]
        keys = map(int, r.readline().strip().split(' '))
        chests = []
        for i in range(0, n):
            chests.append(map(int, r.readline().strip().split(' ')))

        solve_case(keys, chests, case_number)


#invoke main
if __name__ == "__main__":
    main()