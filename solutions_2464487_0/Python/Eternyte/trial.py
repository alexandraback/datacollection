def main():
    fileName = "A-small-attempt0.in"
    file = open(fileName)

    # Loop for the number of tests there are.
    for case in range(1, int(file.readline())+1):
        # Read in the radius and the amount of paint.
        line = file.readline().split()
        radius = int(line[0])
        paintLeft = int(line[1])

        paintNeeded = ((radius + 1)*2)-1
        paintTotal = paintNeeded
        count = 0
        while(paintTotal <= paintLeft):
            count += 1
            paintNeeded = paintNeeded + 4
            paintTotal += paintNeeded

        print("Case #" + str(case) + ": " + str(count))

if __name__ == "__main__":
    main()
