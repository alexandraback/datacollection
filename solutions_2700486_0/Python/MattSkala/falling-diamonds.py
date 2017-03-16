from math import *

filename = "B-small-attempt0"

def solve(count, target_x, target_y):
    probability = 0
    alternatives = []

    for i in range(count):
        if i == 0:
            diamonds = {}
            diamonds['0:0'] = True
            alternatives.append(diamonds)
        else:
            new_alternatives = []
            for diamonds in alternatives:
                # Find empty Y
                y = 0
                while True:
                    if '0:' + str(y) in diamonds:
                        y += 1
                    else:
                        break

                # right
                x_a = 1
                y_a = y
                a_success = False
                while True:
                    diamonds_a = dict(diamonds)
                    if not (str(x_a) + ":" + str(y_a) in diamonds_a):
                        if y_a == 0 or (str(x_a + 1) + ":" + str(y_a - 1) in diamonds_a):
                            diamonds_a[str(x_a) + ":" + str(y_a)] = True
                            new_alternatives.append(diamonds_a)
                            a_success = True
                            break
                        else:
                            x_a += 1
                            y_a -= 1
                    else:
                        break

                # right
                x_b = -1
                y_b = y
                b_success = False
                while True:
                    diamonds_b = dict(diamonds)
                    if not (str(x_b) + ":" + str(y_b) in diamonds_b):
                        if y_b == 0 or (str(x_b - 1) + ":" + str(y_b - 1) in diamonds_b):
                            diamonds_b[str(x_b) + ":" + str(y_b)] = True
                            new_alternatives.append(diamonds_b)
                            b_success = True
                            break
                        else:
                            x_b -= 1
                            y_b -= 1
                    else:
                        break

                # stay
                if not (a_success or b_success):
                    diamonds["0:" + str(y)] = True
                    alternatives.append(diamonds)

            alternatives = new_alternatives

    # count probability
    occurencies = 0
    for diamonds in alternatives:
        if (str(target_x) + ":" + str(target_y) in diamonds):
            occurencies += 1

    probability = occurencies / len(alternatives)
    return probability

fi = open(filename + ".in", "r")
fo = open(filename + ".out", "w")

cases = int(fi.readline())

for case in range(cases):
    line = fi.readline().replace("\n", "")
    count, x, y = [int(num) for num in line.split(" ")]

    result = solve(count, x, y)
    output = "Case #%d: %s" % (case + 1, result)
    print(output)
    fo.write(output + "\n")

fi.close()
fo.close()