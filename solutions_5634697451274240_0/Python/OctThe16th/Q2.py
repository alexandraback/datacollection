f = open('B-small-attempt0.in', 'r')
a = int(f.readline())

for i in range(a):
    flips = 0
    b = f.readline()
    b = b.strip()
    current = b[0]
    for s in b:
        if s != current:
            flips += 1
            if current == "+":
                current = "-"
            else:
                current = "+"
    if current == "-":
        flips += 1
    print("Case #" + str(i + 1) + ": " + str(flips))

