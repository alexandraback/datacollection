infile = open('A-small-attempt0.in', 'r')
cases = int(infile.readline())
outfile = open('outfile1.txt', 'w')
for case in range(1, cases + 1):
    num_class = int(infile.readline())
    classes = [[-1]]*num_class
    for clas in range(num_class):
        line = infile.readline()
        temp = line.split()
        classes[clas] = []
        for i in range(1, int(temp[0]) + 1):
            classes[clas].append((int(temp[i]) - 1))
            
    diamond = False
    for curr_class in range(num_class):
        if diamond:
            break
        def inherit_from(classes, curr_class):
            if curr_class == -1:
                return []
            inher_from = []
            inher_from.extend(classes[curr_class])
            for sup in classes[curr_class]:
                inher_from.extend(inherit_from(classes, sup))
            return inher_from
        paths = inherit_from(classes, curr_class)
        for i in paths:
            if (i in paths[(paths.index(i) + 1):]):
                outfile.write('Case #%d: Yes\n' %case)
                diamond = True
                break
    if not diamond:
        outfile.write('Case #%d: No\n' %case)
infile.close()
outfile.close()
            
        
