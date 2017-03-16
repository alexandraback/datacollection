f = open("A-small-attempt1.in", "r")
g = open("A-small.out", "w")

def check_sleep(c, n, count=0):
    for digit in str(c):
        d.discard(digit)
    if not d: return c
    elif count >= 100: return "INSOMNIA"
    else: return check_sleep(c + n, n, count + 1)

counter = 1
f.readline()
for l in f:
    n = int(l)
    d = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
    g.write("Case #{}: ".format(counter) + str(check_sleep(n, n)) + "\n")
    counter += 1
