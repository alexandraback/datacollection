f = open('D-small-attempt0.in', 'r')
a = int(f.readline())

for i in range(a):
    b = f.readline().strip("\n").split(" ")
    print("Case #" + str(i + 1) + ":", end = " ")
    if (b[0] == b[2]):
        for j in range(int(b[2])):
            print(j+1, end = " ")
        print()
    else:
        print("IMPOSSIBLE")