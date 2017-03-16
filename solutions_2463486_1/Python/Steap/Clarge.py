import math
import sys

pal1 = ['0', '1','2','3','4','5','6','7','8','9']

pal = [ [''], pal1, [], [], [],
        [], [], [], [], [],
        [], [], [], [], [],
        [], [], [], [], []
]

def build(size):
    assert pal[size] == []
    size -= 2
    assert pal[size] != []

    res = []
    for x in pal[1]:
        zislist = pal[size+2]
        l = pal[size]
        for y in l:
            p = [x,y,x]
            zislist.append(''.join(p))
            #pal[size+2].append(x + y + x)
    return pal[size+2]

def is_pal(n):
    s = str(n)
    def pal_aux(s):
        if s == '':
            return True
        if len(s) == 1:
            return True
        if s[0] == s[-1]:
            return pal_aux(s[1:-1])
        return False
    return pal_aux(s)

def main():
    data = sys.stdin.readlines()
    data.pop(0) # T  

    for i in range(2,8):
        build(i)
    for i in range(1,8):
        pal[i] = filter(lambda x:not x.startswith('0'), pal[i])

    for lineno, line in enumerate(data):
        n = 0
        sp = line.split(" ")
        x = int(math.ceil(math.sqrt(int(sp[0]))))
        y = int(math.sqrt(int(sp[1])))

        min_len = len(str(x))
        max_len = len(str(y))
        for size in range(min_len, 1+max_len):
            for palindrom in pal[size]:
                palindrom_i = int(palindrom)
                if palindrom_i < x:
                    continue
                if palindrom_i > y:
                    break
                if is_pal(palindrom_i * palindrom_i):
                    n+=1
        print("Case #%d: %d" % (lineno+1, n))

if __name__ == '__main__':
    main()
