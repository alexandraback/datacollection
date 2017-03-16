o = open("C:\Users\ANTON\PycharmProjects\CodeJam\RevengeOfThePancakes\B-small-attempt0.in")
w = open("C:\Users\ANTON\PycharmProjects\CodeJam\RevengeOfThePancakes\Small-Output.txt", 'w')

input_lines = [[j for j in i.strip('\n')] for i in o]
cases = int(input_lines.pop(0)[0])
for index, stack in enumerate(input_lines):
    last_sign = '+'
    changes = 0
    for sign in reversed(stack):
        if sign != last_sign:
            changes += 1
            last_sign = sign

    w.write("Case #" + str(index + 1) + ": " + str(changes) + '\n')
