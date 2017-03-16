with open("B-small-attempt0.in", "r") as data:
    cases = int(data.readline())
    with open("B-small-attempt0.out", "w") as result:
        for i in range(cases):
            result.write("Case #" + str(i+1) + ": ")
            buildings, routes = (int(x) for x in data.readline().split(" "))
            if 2**(buildings-2) < routes:
                result.write("IMPOSSIBLE\n")
            else:
                result.write("POSSIBLE\n")
                curr = 1
                mat = ""
                if curr == routes:
                    zeros = True
                else:
                    zeros = False
                for j in range(buildings):
                    if zeros:
                        mat += "0" * (buildings-1)
                    else:
                        mat += "0" * j
                        for k in range(buildings-j-1):
                            mat += "1"
                            curr += max(1, 2**(j-2))
                            if curr >= routes:
                                zeros = True
                                mat += "0" * (buildings-j-k-2)
                                break
                    if j == buildings-1:
                        mat += "0\n"
                    else:
                        mat += "1\n"
                dif = curr - routes
                while dif > 0:
                    if dif % 2 != 0:
                        mat = mat[:(2*buildings - 1)] + "0" + mat[(2*buildings):]
                        dif -= 1
                    else:
                        x = 1
                        while 2**x <= dif:
                            x += 1
                        x -= 1
                        index = 2 * buildings - 1 - x
                        while mat[index] != "1":
                            index += buildings + 2
                        mat = mat[:index] + "0" + mat[(index+1):]
                        dif -= 2**x
                result.write(mat)
                
