answers = {}

answers[(3, 3, 5)] = 4
answers[(3, 3, 6)] = 5
answers[(3, 3, 7)] = 6
answers[(3, 3, 8)] = 7
answers[(3, 3, 9)] = 8

answers[(4, 4, 5)] = 4
answers[(4, 4, 6)] = 5
answers[(4, 4, 7)] = 6
answers[(4, 4, 8)] = 6
answers[(4, 4, 9)] = 7
answers[(4, 4, 10)] = 8
answers[(4, 4, 11)] = 8
answers[(4, 4, 12)] = 8
answers[(4, 4, 13)] = 9
answers[(4, 4, 14)] = 10
answers[(4, 4, 15)] = 11
answers[(4, 4, 16)] = 12

answers[(3, 4, 5)] = 4
answers[(3, 4, 6)] = 5
answers[(3, 4, 7)] = 6
answers[(3, 4, 8)] = 6
answers[(3, 4, 9)] = 7
answers[(3, 4, 10)] = 8
answers[(3, 4, 11)] = 9
answers[(3, 4, 12)] = 10

answers[(4, 5, 5)] = 4
answers[(4, 5, 6)] = 5
answers[(4, 5, 7)] = 6
answers[(4, 5, 8)] = 6
answers[(4, 5, 9)] = 7
answers[(4, 5, 10)] = 8
answers[(4, 5, 11)] = 8
answers[(4, 5, 12)] = 8
answers[(4, 5, 13)] = 9
answers[(4, 5, 14)] = 10
answers[(4, 5, 15)] = 10
answers[(4, 5, 16)] = 10
answers[(4, 5, 17)] = 11
answers[(4, 5, 18)] = 12
answers[(4, 5, 19)] = 13
answers[(4, 5, 20)] = 14


answers[(3, 6, 5)] = 4
answers[(3, 6, 6)] = 5
answers[(3, 6, 7)] = 6
answers[(3, 6, 8)] = 6
answers[(3, 6, 9)] = 7
answers[(3, 6, 10)] = 8
answers[(3, 6, 11)] = 8
answers[(3, 6, 12)] = 9
answers[(3, 6, 13)] = 10
answers[(3, 6, 14)] = 10
answers[(3, 6, 15)] = 11
answers[(3, 6, 16)] = 12
answers[(3, 6, 17)] = 13
answers[(3, 6, 18)] = 14


answers[(3, 5, 5)] = 4
answers[(3, 5, 6)] = 5
answers[(3, 6, 7)] = 6
answers[(3, 5, 8)] = 6
answers[(3, 5, 9)] = 7
answers[(3, 5, 10)] = 8
answers[(3, 5, 11)] = 8
answers[(3, 5, 12)] = 9
answers[(3, 5, 13)] = 10
answers[(3, 5, 14)] = 11
answers[(3, 5, 15)] = 12

def read_file():
    file = open("C-small-attempt0.in")
    out = open("OutputC.txt", 'w')
    T = int(file.readline())
    for t in range(1, T+1):
        [A, B, C] = [int(x) for x in file.readline().split()]
        print(A, B, C)
        if C < 5:
            out.write("Case #" + str(t) + ": " + str(C) + "\n")
        elif A <= 2 or B <=2:
            out.write("Case #" + str(t) + ": " + str(C) + "\n")
        else:
            if A != B:
                small = min(A, B)
                big = max(A, B)
                A = small
                B = big
            key = (A, B, C)
            out.write("Case #" + str(t) + ": "+ str(answers[key]) + "\n")
        #PROBLEM CODE GOES HERE5
    out.close()

read_file()
