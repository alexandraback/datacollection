primes = []

for i in range(67000):
    if i < 2:
        continue
    prime = True
    for j in primes:
        if i % j == 0:
            prime = False
            break
    if prime:
        primes.append(i)


values = []
try:
    f = open("c.cache", "r")
    vser = f.read()
    values = eval(vser)
except Exception as e:
    print("Failed to read cache")


if len(values) == 0:
    for i in range(33):
        if i < 2:
            continue
        print("It", i)
        sol = []
        for j in range(1 << (i - 2)):
            ans = []
            ans.append(("1{0:0" + str(i-2) + "b}").format(j) + "1")
            #print(ans)
            #ans.append("1" + bin(j)[:2:-1] + "1")
            for k in range(9):
                v = 0
                base = k + 2
                for l in range(i):
                    v = v * base + int(ans[0][l])
                for z in primes:
                    if z * z > v:
                        break
                    if v % z == 0:
                        ans.append(z)
                        break
                if len(ans) != k + 2:
                    break
            if len(ans) == 10:
                sol.append(ans)
            if len(sol) == 510:
                break
        values.append(sol)

f = open("c.cache", "w")
f.write(str(values))
f.close()

f = open("c.in", "r")
T = int(f.readline())
fout = open("c.out", "w")

for i in range(T):
    l = f.readline()
    fout.write("Case #{0}:\n".format(i + 1))
    l = l.split()
    n = int(l[0])
    j = int(l[1])
    for k in range(j):
        fout.write(" ".join(map(str, values[n - 2][k])) + "\n")
fout.close()
