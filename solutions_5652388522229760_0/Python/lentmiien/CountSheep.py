
# IO files
inputfile = open("A-small-attempt0.in", "r")
outputfile = open("output.txt", "w")

# Test cases
line = inputfile.readline()
cases = int(line) + 1
line = inputfile.readline()

# Solve the cases
for i in range(1, cases):
    if i > 1:
        outputfile.write("\n")
    print(line, end="")
    value = int(line)
    if value == 0:
        # Case #1: INSOMNIA
        print("Result: INSOMNIA")
        outputfile.write("Case #" + str(i) + ": INSOMNIA")
    else:
        # Case #2: 10
        digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        counter = 1
        line = str(value)
        while counter < 1000000:
            stringlength = len(line)
            for j in range(0, stringlength):
                number = int(line[j])
                digits[number] = 1
            iamdone = 1
            for k in range(0, 10):
                if digits[k] == 0:
                    iamdone = 0
            if iamdone == 1:
                break
            counter += 1
            tmpvalue = value * counter
            line = str(tmpvalue)
        result = value * counter
        print("Result: " + str(result))
        outputfile.write("Case #" + str(i) + ": " + str(result))
    line = inputfile.readline()

# Close files
outputfile.close()
inputfile.close()