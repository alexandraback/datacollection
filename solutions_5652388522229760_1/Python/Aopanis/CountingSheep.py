o = open("C:\Users\ANTON\PycharmProjects\CodeJam\A-large.in")
w = open("C:\Users\ANTON\PycharmProjects\CodeJam\CountingSheepLargeOutput.txt", 'w')
input_lines = [i.strip('\n') for i in o]
cases = input_lines.pop(0)

print input_lines

for index, case in enumerate(input_lines):
    last_number = 0
    if int(case) == 0:
        last_number = "INSOMNIA"
    number_set = set([int(x) for x in case])
    N = 2
    tens = range(10)
    while sorted(list(number_set)) != tens and last_number != "INSOMNIA":
        last_number = N * int(case)
        for i in str(last_number):
            number_set.add(int(i))
        N += 1

    w.write("Case #" + str(index + 1) + ': ' + str(last_number) + '\n')
