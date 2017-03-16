import math

infile = open('C-small-attempt1.in', 'r')
outfile = open('try.out', 'w')

st = infile.readline()
st = st.rstrip()
n = int(st)

for m in range(1, n+1):
    st = infile.readline()
    st = st.rstrip()
    sp = st.split(' ')
    outfile.write('Case #' + str(m) + ': ')
    a = int(sp[0])
    b = int(sp[1])
    k = int(sp[2])
    if a > b:
        s = a
        a = b
        b = s
    mint = 99999
    for i in range(k, a*b+1):
        x = i + 4
        y = x
        for j in range(int(math.sqrt(x)), 0, -1):
            if x % j == 0:
                x = x // j - 2
                if j > 2:
                    y = j - 2
                else:
                    y = 0
                break
        if x > y:
            s = x
            x = y
            y = s
        if (y < b) and (x < a):
            t = (x + y) * 2
        else:
            t = 999999
        # print('i : ', i, '  x : ', x, '  y : ', y, '  t :', t)
        if mint > t:
            mint = t
    if mint == 99999:
        if a > 2:
            a1 = a - 2
        else:
            a1 = 0
        if b > 2:
            b1 = b - 2
        else:
            b1 = 0
        mint = a*b - a1*b1
    outfile.write(str(mint) + '\n')

infile.close()
outfile.close()
