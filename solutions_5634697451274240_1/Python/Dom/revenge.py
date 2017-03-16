import ju

results = []
FILE = "B-large"
f = ju.jopen(FILE)

T = int(f.readline())
for t in range(T):
    pancakes = f.readline()[:-1]
    current = "+"
    flips = 0
    for pancake in pancakes[::-1]:
        if pancake != current:
            current = pancake
            flips += 1
    results += [flips]
    print "'" + pancakes + "'", flips

ju.jout(FILE, results)
