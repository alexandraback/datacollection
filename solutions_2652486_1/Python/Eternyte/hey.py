import random

def main():
    fileName = "C-small-2-attempt4.in"
    file = open(fileName)

    writeFile = "answer.txt"
    otherFile = open(writeFile, "w")

    for case in range(1, int(file.readline())+1):
        line = file.readline().split()
        numTurns  = int(line[0])
        numValues = int(line[1])
        maxValue  = int(line[2])
        numProducts = int(line[3])

        otherFile.write("Case #" + str(case) + ":\n")
        for turn in range(numTurns):
            line = file.readline().split()
            line = [int(value) for value in line]
            products = []
            for value in line:
                if value != 1:
                    products.append(value)

            divisibility = [val for val in range(2, maxValue+1)]
            div = [0 for val in range(2, maxValue+1)]
            for product in products:
                tempDiv = [0 for val in range(2, maxValue+1)]
                for index in range(len(divisibility)):
                    while (product != 1 and product % divisibility[index] == 0):
                        product = product / divisibility[index]
                        tempDiv[index] += 1

                for index in range(len(divisibility)):
                    if div[index] < tempDiv[index]:
                        div[index] = tempDiv[index]

            numbers = []
            count = 0
            for index in range(len(div)):
                if div[index] != 0:
                    for _ in range(div[index]):
                        numbers.append(divisibility[index])
                    count += div[index]

            while (len(numbers) > numValues):
                anyChanged = False
                for number in numbers:
                    if (len(numbers) == numValues):
                        anyChanged = False
                        break
                    else:
                        if maxValue >= 4 and numbers.count(2) > 1:
                            numbers.remove(2)
                            numbers.remove(2)
                            numbers.append(4)
                            anyChanged = True
                        elif maxValue >= 6 and numbers.count(2) >= 1 and numbers.count(3) >= 1:
                            numbers.remove(2)
                            numbers.remove(3)
                            numbers.append(6)
                            anyChanged = True
                        elif maxValue >= 8 and numbers.count(2) >= 1 and numbers.count(4) >= 1:
                            numbers.remove(2)
                            numbers.remove(4)
                            numbers.append(8)
                            anyChanged = True
                        elif maxValue >= 9 and numbers.count(3) > 1:
                            numbers.remove(3)
                            numbers.remove(3)
                            numbers.append(9)
                            anyChanged = True
                        elif maxValue >= 9 and numbers.count(6) > 1:
                            numbers.remove(6)
                            numbers.remove(6)
                            numbers.append(4)
                            numbers.append(9)
                            anyChanged = True
                if (anyChanged == False):
                    break

            string = ""
            if (len(numbers) == numValues):
                for number in numbers:
                    string += str(number)
            else:
                for _ in range(numValues):
                    string += str(random.randint(2,maxValue))

            if turn != numTurns-1:
                string += "\n"

            otherFile.write(string)
    file.close()
    otherFile.close()

if __name__ == "__main__":
    main()
