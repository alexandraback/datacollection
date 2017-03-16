import sys

lines = file(sys.argv[1]).readlines()

def parse_line(line):
    ints = line.split(' ')
    return int(ints[0]),int(ints[1]),int(ints[2]),[int(x) for x in ints[3:]]

def get_surprising_min(best):
    min = best * 3;
    if best > 1:
        min -= 4
    else:
        min -= best*2
    return min
def get_unsurprising_min(best):
    if best == 0:
        return 0
    else:
        return get_surprising_min(best) + 2

i = 1
while i <= int(lines[0]):
    num,surprising,best,scores = parse_line(lines[i])
    surprising_min = get_surprising_min(best)
    unsurprising_min = get_unsurprising_min(best)
    non_surprising = [x for x in scores if x >= unsurprising_min]
    only_surprising = [x for x in scores if x in range(surprising_min,unsurprising_min)]
    possible_count = len(non_surprising)
    if len(only_surprising) <= surprising:
        possible_count += len(only_surprising)
    else:
        possible_count += surprising
    print "Case #"+str(i)+": " + str(possible_count)
    i+=1

