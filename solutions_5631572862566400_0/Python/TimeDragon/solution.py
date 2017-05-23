#!python3

inputFile = open("input.txt", "r")
outputFile = open("output.txt", "w")

testCases = int(inputFile.readline())

for i in range(0, testCases):

    ListN = int(inputFile.readline())
    arr = [0]
    ListC = inputFile.readline().split()
    for j in range(0, ListN):
        arr += [int(ListC[j])]

    mx = [-1] * (ListN + 1)
    start = [-1] * (ListN + 1)
    end = [-1] * (ListN + 1)
    for j in range(1, ListN + 1):
        ar = [0] * (ListN + 1)
        count = 1
        nxt = j
        if mx[j] > 0:
            continue
        while True:
            ar[nxt] = count
            if ar[arr[nxt]]:
                break
            nxt = arr[nxt]
            count += 1
        again = j

        if (ar[arr[nxt]] == count-1):
            while again != nxt:
                if mx[again] < count:
                    mx[again] = count
                    start[again] = j
                    end[again] = nxt
                again = arr[again]
            if mx[again] < count:
                mx[again] = count
                start[again] = j
                end[again] = nxt
        elif (ar[arr[nxt]] == 1):
            while again != nxt:
                if mx[again] < count:
                    mx[again] = count
                    start[again] = again
                    end[again] = again
                again = arr[again]
            if mx[again] < count:
                mx[again] = count
                start[again] = again
                end[again] = again
        else:
            count = ar[nxt] - ar[arr[nxt]] + 1
            again = arr[nxt]
            while again != nxt:
                if mx[again] < count:
                    mx[again] = count
                    start[again] = again
                    end[again] = again
                again = arr[again]
            if mx[again] < count:
                mx[again] = count
                start[again] = again
                end[again] = again

    res = []
    for j in range(1, ListN + 1):
        res += [[mx[j], j]]

    res.sort(reverse=True)
    ans = res[0][0]
    done = [0] * (ListN + 1)
    for j in range(0, ListN):
        ind = res[j][1]
        rs = res[j][0]
        if end[ind] != ind:
            s = start[ind]
            e = end[ind]
            if done[s]:
                continue
            done[s] = 1
            visited = [0] * (ListN + 1)
            visited[s] = 1
            k = s
            while k != e:
                k = arr[k]
                visited[k] = 1

            cnt = 0
            for l in range(1, ListN + 1):
                visit = [0] * (ListN + 1)
                k1 = l
                crn = 0
                while k1 != e:
                    if visited[k1] or visit[k1]:
                        crn = 0
                        break
                    visit[k1] = 1
                    k1 = arr[k1]
                    crn += 1
                else:
                    if cnt < crn:
                        cnt = crn
            rs += cnt
        if ans < rs:
            ans = rs
    print("Case #", i + 1, ": ", ans, sep="", file=outputFile)
