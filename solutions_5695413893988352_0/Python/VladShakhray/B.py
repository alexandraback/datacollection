fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())

gen = []

def generate(a, b):
    if '?' in a:
        for i in range(10):
            generate(a[:a.index('?')] + str(i) + a[a.index('?')+1:], b)
    elif '?' in b:
        for i in range(10):
            generate(a, b[:b.index('?')] + str(i) + b[b.index('?')+1:])
    else:
        gen.append((a, b))

for test in range(1, t + 1):
    print()
    a, b = fin.readline().split()
    gen = []
    generate(a, b)
    ans = (0, 999999)
    ans_ind = 0
    for i in range(len(gen)):
        f = gen[i][0]
        s = gen[i][1]
        if abs(int(f)-int(s))<abs(int(ans[0]) -  int(ans[1])):
            ans = (f, s)
        elif abs(int(f)-int(s))==abs(int(ans[0])-int(ans[1])):
            if int(ans[0]) > int(f) or (int(ans[0]) == int(f) and int(ans[1]) > int(s)):
                ans = (f, s)
    fout.write("Case #" + str(test) + ': ' + ans[0] + ' ' + ans[1] + '\n')
fin.close()
fout.close()
