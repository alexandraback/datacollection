def main():
    fileName = "B-large.in"
    file = open(fileName)

    # Loop for the number of tests there are.
    for case in range(1, int(file.readline()) + 1):
        # Read in the values.
        values = file.readline().split()
        cookies = float(values[0])
        farmBonus = float(values[1])
        winningCondition = float(values[2])
        rateOfCookies = 2

        totalTime = 0
        while(True):
            # Calculate the time needed until you can buy a farm.
            tempTime = cookies/rateOfCookies

            # Calculate the time needed with a farm to finish.
            withFarm = tempTime + \
                            winningCondition/(rateOfCookies + farmBonus)
            
            # Calculate the time needed without a farm to finish.
            withoutFarm = winningCondition/rateOfCookies

            # Find the shorter time and add it to the total time.
            if (withFarm <= withoutFarm):
                totalTime += tempTime
                rateOfCookies += farmBonus
            elif (withoutFarm < withFarm):
                totalTime += withoutFarm
                print("Case #" + str(case) + ": ", "%.7f" % totalTime)
                break

if __name__ == "__main__":
    main()
