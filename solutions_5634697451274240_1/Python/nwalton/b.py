def pmstr_to_pair(str):
    length = len(str)
    num_alternates = 1
    for ind in range(0,length-1):
        if str[ind:ind+2] in ['+-', '-+']:
            num_alternates += 1
    return (str[0], num_alternates)


def pair_flips(str):
    startSymb, num_alternates = pmstr_to_pair(str)
    if startSymb == '+':
        return 2*(num_alternates/2)
    else:
        return 2*((num_alternates-1)/2)+1

f = open("input.txt", 'r')
g = open("output.txt", 'w')

num_cases = int(f.readline().strip())
for case in range(1, num_cases+1):
    g.write("Case #" + str(case) + ": " + str(pair_flips(f.readline().strip())))
    if case != num_cases:
        g.write("\n")
