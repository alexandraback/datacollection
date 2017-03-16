import random
N = 16
J = 50
seq = []
Hash = {}
for i in range(N) :
    seq.append(1)
print("Case #1:")
for test in range(J) :
    while True :
        for i in range(1, N - 1) :
            seq[i] = random.randint(0, 1)
        divisor = []
        for d in range(2, 11) :
            val = 0
            for i in range(N) :
                val = val * d + seq[i]
            for i in range(2, 100) :
                if val % i == 0 :
                    divisor.append(i)
                    break
            if len(divisor) != d - 1 :
                break
        if len(divisor) == 9 :
            string = ""
            for i in range(N) :
                string += chr(ord('0') + seq[i])
            if not string in Hash :
                Hash[string] = True
                print(string, end = "")
                for div in divisor :
                    print(" %d" % div, end = "")
                print()
                break
