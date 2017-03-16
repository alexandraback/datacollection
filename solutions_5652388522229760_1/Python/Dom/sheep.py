import ju, random

results = []
FILE = "A-large"
f = ju.jopen(FILE)

T = int(f.readline())
for t in range(T):
    N = int(f.readline())
    if N == 0:
        results += ["INSOMNIA"]
        print N,"INSOMNIA"
        continue
    digitsSeen = {}
    multiplier = 1
    next = N
    while True:
        next = N * multiplier
        for digit in str(next):
            digitsSeen[digit] = 1
        if len(digitsSeen) == 10:
            results += [next]
            print N,next
            break
        multiplier += 1

ju.jout(FILE, results)
