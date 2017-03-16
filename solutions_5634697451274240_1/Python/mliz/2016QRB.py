with open("B-large.in", "r") as data:
    cases = int(data.readline())
    with open("B-large.out", "w") as result:
        for i in range(cases):
            pancakes = data.readline().rstrip()
            moves = 0
            if "-" not in pancakes:
                result.write("Case #" + str(i+1) + ": " + str(moves) + "\n")
            else:
                cont = True
                while cont:
                    first = pancakes[0]
                    for j in range(len(pancakes)):
                        if pancakes[j] != first:
                            if first == "-":
                                pancakes = ("+" * j) + pancakes[j:]
                            else:
                                pancakes = ("-" * j) + pancakes[j:]
                            moves += 1
                            break
                        if j == len(pancakes) - 1:
                            cont = False
                if "-" not in pancakes:
                    result.write("Case #" + str(i+1) + ": " + str(moves) + "\n")
                else:
                    result.write("Case #" + str(i+1) + ": " + str(moves+1) + "\n")
                                    
                            
                
            
