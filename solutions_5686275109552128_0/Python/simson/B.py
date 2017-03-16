import sys
from bintrees.rbtree import RBTree

def get_line():
    return sys.stdin.readline()

def get_ints():
    return [int(i) for i in get_line().split()]

def rem(tree, key):
#    print("rem", key)
    v = tree.get(key)
    if v>1:
        tree.insert(key, v - 1)
    else:
        tree.pop(key)

def add(tree, key):
#    print("add", key)
    v = tree.get(key)
    if v:
        tree.insert(key, v + 1)
    else:
        tree.insert(key, 1)

def ftry(pan, maxx):
    tree = RBTree()
    for i in pan:
        add(tree, i)
    shift = 0
    
    while (tree.max_key() - shift) > 0:
        v = tree.max_key()
        val = v - shift
        shift += 1
#        print(maxx, shift, val, tree)
        if (val > 3):
            v1 = (val // 2) if (maxx == 0) else (maxx - shift)
            v2 = val - v1
            if v1 + shift < v:
                rem(tree, v)
                add(tree, v2 + shift)
                add(tree, v1 + shift)
        if maxx > 0 and shift == maxx:
            return 1e10
    return shift
    
for e,n in enumerate(range(get_ints()[0])):
    get_line()
    pan = get_ints()
    
    f = ftry(pan, 0)
    t = f - 1
    while ftry(pan, t) <= t :
        t -= 1
        
    print("Case #%i: %i" % (e+1, t+1))
                