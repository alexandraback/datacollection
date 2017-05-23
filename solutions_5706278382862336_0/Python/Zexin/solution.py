infile = open('A-small-attempt1 (1).in', 'r')
outfile = open('try.out', 'w')

st = infile.readline()
st = st.rstrip()
n = int(st)

for m in range(1, n+1):
    st = infile.readline()
    st = st.rstrip()
    sp = st.split('/')
    outfile.write('Case #' + str(m) + ': ')
    a = int(sp[0])
    b = int(sp[1])
    q = b
    while (q % 2 == 0):
        q = q // 2
    if (a % q == 0):
        a = a // q
        b = b // q
        x = 0
        while a < b:
            a = a * 2
            x += 1
        outfile.write(str(x) + '\n')
    else:
        outfile.write('impossible\n')

infile.close()
outfile.close()
