import sys

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

def find_bigger(ken, num):
    for k in range(len(ken)):
        if ke[k] > num:
            return k

for i in range(T):
    N = int(file.readline())
    dwar = 0
    war = 0

    naomi = sorted([float(z) for z in file.readline().split()])
    ken = sorted([float(z) for z in file.readline().split()])

    ke = ken.copy()
    for j in range(N):
        if naomi[j] > ke[len(ke) - 1]:
            war += 1
            del ke[0]
        elif naomi[j] < ke[0]:
            del ke[0]
        else:
            idx = find_bigger(ke, naomi[j])
            del ke[idx]

    ni, ki = 0, 0
    while ni < len(naomi):
        while ni < len(naomi) and naomi[ni] < ken[ki]:
            del ken[len(ken)-1]
            ni += 1
        while ni < len(naomi) and naomi[ni] > ken[ki]:
            dwar += 1
            ni += 1
            ki += 1

    print("Case #%d: %d %d"%(i+1, dwar, war))
