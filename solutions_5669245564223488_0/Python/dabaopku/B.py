
# coding: utf-8

# In[2]:

cin = None
cout = None


# In[3]:

def read():
    global cin
    return cin.readline().strip().split()

def read_int():
    return [int(x) for x in read()]
    
def write(fmt, data=None):
    global cout
    cout.write(data is None and str(fmt) or fmt % data)
    
def write_line():
    write('\n')


# In[1]:

def work(id):
    global cin, cout
    case_num = 0
    cin = file('%s.in' % id, 'r')
    cout = file('%s.out' % id, 'w')
    case_num = read_int()[0]
    
    for i in range(case_num):
        write('Case #%d: ', i + 1)
        solve()
        write('\n')
    cin.close()
    cout.close()


# In[134]:

import math
import copy
def solve():
    read()
    words = read()
    #print words
    struct = []
    id = 0
    same = {}
    for w in words:
        id += 1
        if len(w) == 1:
            w = w + w
        s = w[0]
        e = w[-1]

        if s == e:
            for c in w[1:-1]:
                if c != s:
                    write(0)
                    return
            if s not in same:
                same[s] = 1
                struct.append((s, e, [], id))
            else:
                same[s] += 1
        else:
            pre = None
            cnt = {}
            for c in w[1:-1]:
                if c != s and c != e:
                    #print c
                    if c != pre and pre and c in cnt:
                        write(0)
                        return
                    pre = c
                    cnt[c] = True
            struct.append((s, e, cnt.keys(), id))
    
    #print struct
    found = None
    cnt = 1
    while True:
        for w1 in struct:
            s = w1[0]
            e = w1[1]
            for w2 in struct:
                if w1[3] == w2[3]:
                    continue
                if s in w2[2] or e in w2[2] or (s == w2[0] and w2[0] != w2[1]):
                    if s != e:
                        #print w1, w2
                        write(0)
                        return
                    else:
                        found = [w1, w2, True]
                        break
                #print w1, w2
                for c in w1[2]:
                    if c in w2[2]:
                        write(0)
                        return
                for c in w2[2]:
                    if c in w1[2]:
                        write(0)
                        return
                if w1[1] == w2[0]:
                    found = [w1, w2, False]
                    break
                if w1[0] == w2[1]:
                    found = [w2, w1, False]
                    break
            if found:
                break
        if found:
            struct.remove(found[0])
            struct.remove(found[1])
            w1 = found[0]
            w2 = found[1]
            if found[2]:
                merge = w2
                struct.append(merge)
                pass
            else:
                x = copy.copy(w1[2])
                if w1[1] != w1[0] and w1[1] != w2[1]:
                    x.extend([w1[1]])
                x.extend(w2[2])
                id += 1
                merge = (w1[0], w2[1], x, id)
                struct.append(merge)
            #print found, merge
            found = None
        else:
            break
    
    #print struct
    for s in struct:
        if s[0] == s[1] and len(s[2]) > 0:
            write(0)
            return
    n = len(struct)
    #print struct, same
    while n:
        cnt = cnt * n % 1000000007
        n -= 1
    for k in same:
        n = same[k]
        while n:
            cnt = cnt * n % 1000000007
            n -= 1
    write(cnt)
id = 'B'
work(id)
with open('%s.out' % id) as f:
    print f.read()


# In[129]:




# In[ ]:



