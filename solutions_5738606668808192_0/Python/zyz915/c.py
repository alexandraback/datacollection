import random

def gen_lst(n):
    ret = [1]
    for i in range(2, n):
        ret.append(random.randint(0, 1));
    ret.append(1);
    return ret;

def get_num(x, b):
    ret = 0;
    for i in x:
        ret = ret * b + i
    return ret

def get_div(x):
    i = 2;
    while (i*i<=x and i < 10000):
        if (x % i == 0):
            return i;
        i += 1
    return -1;

print "Case #1:"

ans = []
while (len(ans) < 50):
    x = gen_lst(16)
    f = True
    divs = []
    for j in range(2, 11):
        y = get_num(x, j)
        d = get_div(y)
        if (d == -1):
            f = False
            break
        divs.append(d)
    if f:
        ans.append((x, divs))
        s = ""
        for ch in x:
            s += str(ch)
        for div in divs:
            s += " " + str(div)
        print s

