
# Helper function
def is_prime(n):
    if n <= 1:
        return -1
    elif n <= 3:
        return 0
    elif n%2 == 0:
        return 2
    elif n%3 == 0:
        return 3
    i = 5
    while i*i <= n:
        if n%i == 0:
            return i
        elif n%(i+2) == 0:
            return (i+2)
        i += 6
    return 0

# IO files
inputfile = open("input.txt", "r")
#inputfile = open("A-small-attempt0.in", "r")
#inputfile = open("A-large.in", "r")
outputfile = open("output.txt", "w")

# Test cases
line = inputfile.readline()
cases = int(line) + 1
line = inputfile.readline()
space = line.find(" ")
size = int(line[0:space])
results = int(line[space+1:])
current = 0

outputfile.write("Case #1:\n")

# Solve case
for j in range(0, 2 ** (size-2)):
    isok = 1
    realj = (2 ** (size-1)) + (j*2) + (1)
    tal = bin(realj)[2:]
    resultstring = ""
    for k in range(2, 11):
        c = int(tal, k)
        test = is_prime(c)
        if test == 0:
            isok = 0
        elif test > 0:
            resultstring += str(test) + " "
    if isok == 1:
        current += 1
        print("JamCoin(" + str(current) + "): " + tal + " " + resultstring[0:-1])
        outputfile.write(tal + " " + resultstring[0:-1])
        if current < results:
            outputfile.write("\n")
    if current >= results:
        break

# Close files
outputfile.close()
inputfile.close()