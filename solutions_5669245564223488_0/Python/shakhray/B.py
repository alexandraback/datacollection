fin = open("input.txt", 'r')
fout = open("output.txt", 'w')

tests = int(fin.readline())
perms = []


def add_perms(curr, length, list_, N, trains):
    if length == N:
        perms.append(curr)
        return
    for i in range(len(list_)):
        if len(curr) == 0:
            add_perms(curr + list_[i], length + 1, list_[:list_.index(list_[i])] + list_[list_.index(list_[i]) + 1:], N, trains)
        else:
            j = int(curr[-1])
            if trains[j][-1] == trains[int(i)][0]:
                add_perms(curr + list_[i], length + 1, list_[:list_.index(list_[i])] + list_[list_.index(list_[i]) + 1:], N, trains)


def check(string):
    elems = []
    for elem in string:
        if elem not in elems:
            elems.append(elem)
    for elem in elems:
        i = string.index(elem)
        while i < len(string) and string[i] == elem:
            i += 1
        string = string[:string.index(elem)] + string[i:]
        if elem in string:
            return 0
    return 1


def check_1(trains, N):
    for train in trains:
        el0 = train[0]
        i = 0
        while i < len(train) and train[i] == el0:
            i += 1
        if i < len(train) - 1:
            el1 = train[i]
            while i < len(train) and train[i] == el1:
                i += 1
            if i < len(train):
                for train1 in trains:
                    if train1 != train and el1 in train1:
                        return 0
    for train in trains:
        if len(train) > 2:
            for i in range(len(train) - 1):
                for j in range(i + 1, len(train)):
                    if train[i] == train[j]:
                        for k in range(i, j):
                            if train[k] != train[i]:
                                return 0

    return 1


def optimize(trains, N):
    begs = [elem[0] for elem in trains]
    ends = [elem[-1] for elem in trains]
    can_optimize = 0
    for elem in begs:
        c0 = 0
        c1 = 0
        for elem1 in begs:
            if elem1 == elem:
                c0 += 1
        if c0 == 1:
            for elem1 in ends:
                if elem1 == elem:
                    c1 += 1
            if c1 == 1:
                can_optimize = 1
        if can_optimize == 1:
            for i in range(N):
                if trains[i][0] == elem:
                    for j in range(N):
                        if trains[j][-1] == elem and i != j:
                            trains[i] = trains[j] + trains[i]
                            trains.pop(j)
                            return trains, N - 1
    return trains, N


for test in range(tests):
    print(test)
    N = int(fin.readline())
    trains = list(fin.readline().split())
    a = check_1(trains, N)
    if not a:
        fout.write("Case #" + str(test + 1) + ": 0\n")
        continue
    for i in range(N):
        if len(trains[i]) > 1:
            trains[i] = trains[i][0] + trains[i][-1]
    perms = []
    add_perms('', 0, [str(i) for i in range(N)], N, trains)
    count = 0
    for elem in perms:
        res = ''
        for ind in elem:
            res += trains[int(ind)]
        if check_1([res], 1):
            count += 1
    fout.write("Case #" + str(test + 1) + ": " + str(count) + '\n')


fin.close()
fout.close()


