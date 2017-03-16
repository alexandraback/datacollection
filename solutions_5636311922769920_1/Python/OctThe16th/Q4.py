f = open('D-large.in', 'r')
a = int(f.readline())

for i in range(a):
    b = f.readline().strip("\n").split(" ")

    initial = int(b[0])
    puissance = int(b[1])
    essaie = int(b[2])

    print("Case #" + str(i + 1) + ":", end = " ")
    if puissance == 1:
        if essaie != initial:
            print("IMPOSSIBLE", end = " ")
        else:
            for j in range(essaie):
                print(j+1, end = " ")
    elif (essaie < initial//2):
        print("IMPOSSIBLE", end = " ")
    else :
        for k in range(initial):
            if(k%2 == 0):
                if k != initial - 1:
                    print(k*initial + k + 2, end = " ")
                else:
                    print(k*initial+k+1, end = " ")
    print()


