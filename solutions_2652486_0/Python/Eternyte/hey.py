import random

def main():
    fileName = "C-small-1-attempt1.in"
    file = open(fileName)

    for case in range(1, int(file.readline())+1):
        line = file.readline().split()
        numTurns  = int(line[0])
        numValues = int(line[1])
        maxValue  = int(line[2])
        numProducts = int(line[3])

        print("Case #" + str(case) + ":")
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
                for index in reversed(range(len(divisibility))):
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

            anyChanged = False
            while (len(numbers) < numValues):
                for number in numbers:
                    if (len(numbers) < numValues):
                        if number == 9:
                            numbers.remove(9)
                            numbers.append(3)
                            numbers.append(3)
                            anyChanged = True
                        elif number == 8:
                            numbers.remove(8)
                            numbers.append(2)
                            numbers.append(4)
                            anyChanged = True
                        elif number == 6:
                            numbers.remove(6)
                            numbers.append(2)
                            numbers.append(3)
                            anyChanged = True
                        elif number == 4:
                            numbers.remove(4)
                            numbers.append(2)
                            numbers.append(2)
                            anyChanged = True
                if (anyChanged == False):
                    break

            if (len(numbers) == numValues):
                for number in numbers:
                    print(number, end="")
                print()
            else:
                for _ in range(numValues):
                    print(random.randint(2,maxValue), end="")
                print()

if __name__ == "__main__":
    main()
