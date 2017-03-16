def sol():
    def firstqn(C,D,l,V):
        def curDtraversal(C,_l,val,dict_v):
            if (len(_l)==0):
                return
            for i in range(0,C+1,1):
##                print val, i, _l[0]
                newval = val+i*_l[0]
                if (dict_v.has_key(newval)):
                    dict_v[newval]=True
                    __l = _l[1:]
                    curDtraversal(C,__l,newval,dict_v)
        dict_v = {}
        for v in range(0,V+1,1):
            dict_v[v] = False
        #all possibilities of current value
        curDtraversal(C,l,0,dict_v)
##        print dict_v #cur possibile values
        for v in range(1,V+1,1):
            if (dict_v[v]): #if dict_v[v] is true, element is covered. Next.
                continue
            #else, add the element.
            l.append(v)
            #set true all possiblities for new element
            old_possibles = []
            for key in dict_v.keys():
                if (dict_v[key]):
                    old_possibles.append(key)
##            print old_possibles
            for i in range(1,C+1,1):
                for key in old_possibles:
                    val = key+i*v
                    if (dict_v.has_key(val)):
                        dict_v[val] = True
        print "L:",l
##        print "FINAL\n", dict_v #final possibile values
        return len(l)-D
    global line_counter
    data = inp[line_counter].split()
    line_counter+=1
    C = int(data[0])
    D = int(data[1])
    V = int(data[2])
    _l = inp[line_counter].split()
    line_counter+=1
    l = []
    for data in _l:
        l.append(int(data))
    return str(firstqn(C,D,l,V))
    
##with open('lol.txt', 'r') as f:
with open('C-small-attempt1.in', 'r') as f:
##with open('A-large (2).in', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    print i
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
print data
print 'done!'
