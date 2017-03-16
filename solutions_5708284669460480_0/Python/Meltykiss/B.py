import sys

f = open('B-small.in')
f_out = open('B-small.out', 'w')

def count(strA, strB):
    c = 0
    for i in range(len(strA)-len(strB)+1):
        if strA[i:i+len(strB)]==strB:
            c += 1
    return c
def generate(ctStr, pos):
    global maxTimes, totTimes, S, keyboard, string
    if pos == S:
        times = count(ctStr, string)
        if times > maxTimes:
            maxTimes = times
        totTimes += times
    else:
        for ch in keyboard:
            generate(ctStr+ch, pos+1)
    return

T = int(f.readline())
for k in range(T):
    line = f.readline().split()
    K = int(line[0])
    L = int(line[1])
    S = int(line[2])
    keyboard = f.readline().rstrip()
    string = f.readline().rstrip()
    maxTimes, totTimes = 0, 0
    generate('', 0)
    print maxTimes, totTimes
    ans = maxTimes*1.0-totTimes*1.0/pow(K, S)
    f_out.write('Case #{0}: {1}\n'.format(k+1, ans))

f.close()
f_out.close()
