import sys

def case(idx, classes):
    b = True
    
    while b:
        b = False
        for i in xrange(len(classes)):
            #import pdb; pdb.set_trace()
            
            fl,cl,deps = classes[i]
            if not fl and not deps:
                for j in xrange(len(classes)):
                    if i != j and classes[j][2].count(i) > 0:
                        classes[j][1].extend(classes[i][1])
                        classes[j][2].remove(i)
                classes[i][0]=True
                b=True
    
    for fl,cl,deps in classes:
        if len(set(cl))<len(cl):
            print "Case #%s: Yes" % idx
            return
    print "Case #%s: No" % idx


lines = open(sys.argv[1]).readlines()
T = int(lines[0])
cur_line = 1
for idx in xrange(T):
    n = int(lines[cur_line])
    classes = []

    cur_line += 1

    for i in xrange(n):
        classes.append([False,[i],[int(x) - 1 for x in lines[cur_line].split()[1:]]])
        cur_line += 1
    
    case(idx + 1, classes)
