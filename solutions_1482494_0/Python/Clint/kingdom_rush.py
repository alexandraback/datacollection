def descending_two(x, y):
    if x[1] > y[1]: return -1
    if x[1] == y[1]:
        if x[0] > y[0]: return -1
        if x[0] == y[0]: return 0
    return 1
    
def descending_one(x, y):
    if x[0] > y[0]: return -1
    if x[0] == y[0]:
        if x[1] > y[1]: return 1
        if x[1] == y[1]: return 0
    return 1


from sys import argv
script, file_name = argv

in_file = open(file_name, 'r')

for t in range(int(in_file.readline())):
    level = []
    for n in range(int(in_file.readline())):
        level.append([int(j) for j in in_file.readline().split(' ')])
    
    possible = True
    level_count = 0
    stars = 0
    while len(level) > 0:
        level.sort(descending_two)
        if stars >= level[-1][1]:
            stars += 2
            level.pop()
        else:
            level.sort(descending_one)
            if stars >= level[-1][0] and level[-1][0] >= 0:
                stars += 1
                level[-1][0] = -1
            else:
                possible = False
                break;
        level_count += 1
            
    if possible: print "Case #%d: %d" % (t+1, level_count)
    else: print "Case #%d: Too Bad" % (t+1)

in_file.close()
