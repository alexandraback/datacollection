def divisors(nb):
    i = 2
    while i <= 100000:
        if nb % i == 0 and nb != i:
            return i
        i += 1
    return -1;

def check_nb(stringi, index):
    mylist = []
    for base in range(2, 11):
        nb = int(string, base)
        div = divisors(nb)
        if div == -1:
            return False
        mylist.append(div)
    print(string, end='')
    for n in mylist:
        print(" " + str(n), end="")
    print("")
    return True

T = int(input())
N_, nb_ = input().split()
N = int(N_)
nb = int(nb_)
maximum_range = pow(2, N - 2)
index = 1
print("case #1:")
for i in range(maximum_range):
    string = "1"
    tmp = bin(i)[2:]
    tmp = tmp.rjust(N - 2, '0')
    for j in tmp:
        string += j
    string += '1'
    if (check_nb(string, index)):
        index += 1
    if (index > nb):
        exit()
