with open("A-large.in", "r") as data:
    cases = int(data.readline())
    with open("A-large.out", "w") as result:
        for i in range(cases):
            count = []
            num = int(data.readline())
            if num == 0:
                result.write("Case #" + str(i+1) + ": INSOMNIA\n")
            else:
                j = 1
                while True:
                    curr = str(j * num)
                    for digit in curr:
                        if digit not in count:
                            count.append(digit)
                    if len(count) == 10:
                        result.write("Case #" + str(i+1) + ": " + curr + "\n")
                        break
                    j += 1
        
