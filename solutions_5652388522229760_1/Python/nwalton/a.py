from pefuncs import digits

def bleatrix_last(n):
    if n == 0:
        return "INSOMNIA"
    i = 0
    multiple = 0
    unseen_digits = range(0,10)
    while i <= 100 and unseen_digits != []:
        i += 1
        multiple = i*n
        for dig in digits(multiple):
            if dig in unseen_digits:
                unseen_digits.remove(dig)
    if unseen_digits == []:
        return multiple
    else:
        return "INSOMNIA", unseen_digits

f = open("input.txt", 'r')
g = open("output.txt", 'w')

num_cases = int(f.readline().strip())
for case in range(1,num_cases+1):
    g.write("Case #" + str(case) + ": " + str(bleatrix_last(int(f.readline().strip()))))
    if case != num_cases:
        g.write("\n")
