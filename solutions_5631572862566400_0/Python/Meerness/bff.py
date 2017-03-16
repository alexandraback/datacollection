def get_longest_loop(friends):
    friends = [int(x) for x in friends]
    pairs = set()
    max_for_pairs = dict()
    max_loop_size = 0
    for person in range(len(friends)):
        person += 1
        in_loop = True
        current_loop = {}
        while in_loop:
            if person in current_loop:
                in_loop = False
                if len(current_loop) - current_loop[person] == 2:
                    pairs.add(tuple(sorted((person, friends[person - 1]))))
                    max_for_pairs[person] = len(current_loop) if person not in max_for_pairs else max(len(current_loop),
                                                                                                      max_for_pairs[person])
                else:
                    max_loop_size = max(max_loop_size, len(current_loop) - current_loop[person])
            else:
                current_loop[person] = len(current_loop)
                person = friends[person - 1]
    for person1, person2 in pairs:
        max_loop_size = max(max_loop_size, max_for_pairs[person1] + max_for_pairs[person2] - 2)
    return max_loop_size


with open("input.txt") as f:
    with open("output.txt", "w") as outf:
        for i, line in enumerate(f):
            if i == 0 or i % 2 == 1:
                continue
            else:
                outstring = str(get_longest_loop(line.strip().split(" ")))
                outf.write("Case #" + str(i/2) + ": " + outstring + "\n")