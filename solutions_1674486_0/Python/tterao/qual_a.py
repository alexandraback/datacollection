'''
Created on 2012/04/14

@author: teraotsuyoshi
'''

flag = False

def make_tree(idx, tree, cls):
    if len(cls[idx]) == 0:
        tree[idx] = set()
        tree[idx].add(idx)
        return
    if not tree[idx] == None:
        return
    
    tree[idx] = set()
    tree[idx].add(idx) 
    for x in cls[idx]:
        make_tree(x, tree, cls)
        tree[idx] |= tree[x]
        tree[idx].add(x)
        

if __name__ == '__main__':

    lines = open("A-small-attempt1.in").readlines()
    T = int(lines[0])
    
    li = 1
    
    for t in range(1, T+1):
        flag = False
        N = int(lines[li])
        li = li + 1
                
        cls = [set()]
        tree = [None]
        for n in range(N):
            M = int(lines[li].split()[0])
            
            inh = set()
            for m in range(1,M + 1):
                inh.add(int(lines[li].split()[m]))
            cls.append(inh)
            tree.append(None)
            
            li = li + 1
        
        for n in range(1,N+1):
            make_tree(n, tree, cls)
            if flag:
                break
    
        for n in range(1, N+1):
            if len(cls[n]) < 2:
                continue
            cls2 = cls[n].copy()
            for x in cls2:
                for y in cls2:
                    if x >= y:
                        continue
                    if len(tree[x] & tree[y]) > 0:
#                        print n, x, y, cls[x], cls[y]
#                        for xx in cls[x]:
#                            print "x", xx, cls[xx]
#                        for yy in cls[y]:
#                            print "y", yy, cls[yy]                        
#                        print tree[x]
#                        print tree[y]
#                        print tree[x] & tree[y]
                        flag = True
                        break
                
        
        print "Case #%d: "%t, 
        if flag:
            print "Yes"
        else:
            print "No"
    
#    for i,line in enumerate(lines):
#        if i == 0:
#            continue

#        eng = ""
#        for c in line.strip():
#            eng = eng + gdict[c]
#        print eng
        
        
    
