__author__ = 'Owen'

def Fractiles(k, c, s):
    sol = ""
    if k == s:
        for i in range(1, k+1):
            sol += str(i)+" "
    else:
        return
    return sol




f = open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\D-small-attempt1.in", "r")
a = []
for line in f:
    a.append(line)

print a
print a[0]


with open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\SolFractilesSmall.txt", "w") as text_file:
    for i in range(int(a[0])):
        arr = a[i+1].split(" ")
        k = arr[0]
        c = arr[1]
        s = arr[2]

        text_file.write("Case #%s: %s\n" %(i+1, Fractiles(int(k), int(c), int(s))))


