f = open('C:\\Users\\djspence\\Downloads\\A-small-attempt0.in', 'r')

tries = int(f.readline())

for i in range(0, tries):
    number = int(f.readline())
    if number == 0:
        print("Case #" + str(i+1) + ": INSOMNIA")
        continue
    seen = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    seenNum = 0
    origNum = number
    while True:
        breaking = 0
        for j in range(0, len(str(number))):
            dig = int(str(number)[j])
            if seen[dig] == 0:
                seenNum += 1
                if seenNum == 10:
                    print("Case #" + str(i+1) + ": " + str(number))
                    breaking = 1
            seen[dig] = 1
            if breaking == 1:
                break
        if breaking == 1:
            break
        number = number + origNum