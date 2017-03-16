from random import randint
T = int(raw_input())

for i in range(T):
    C, J = raw_input().split()

    while '?' in C:
        C = C.replace('?', str(randint(0,9)), 1)
    while '?' in J:
        J = J.replace('?', str(randint(0,9)), 1)

    print("Case #%d: %s %s" % (i+1, C, J))
