__author__ = 'Owen'

def CountingSheep(N):
    if N == 0:
        return "INSOMNIA"

    seen = []
    for i in str(N):
        if i not in seen:
            seen.append(i)
    k = N
    c = 0



    while(c != 10):
        c = 0
        k += N
        for l in str(k):
            if l not in seen:
                seen.append(l)

        for r in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]:
            if r in seen:
                c += 1

    return str(k)

f = open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\A-small-attempt3.in", "r")
a = []
for line in f:
    a.append(line)

print a
print a[0]


with open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\SolCountingSheepSmall.txt", "w") as text_file:
    for i in range(int(a[0])):
        text_file.write("Case #%s: %s \n" %(i+1, CountingSheep(int(a[i+1]))))





