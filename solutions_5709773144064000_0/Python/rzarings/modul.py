def main():
    with open('G:\Documents and Settings\Masta\Desktop\input5.in') as f:
        testNo = int(f.readline())
        for a in range(testNo):
            time = 0.
            cps = 2.
            data = f.readline().split() # 0 = farm price, 1 = farm cps, 2 = goal
            price = float(data[0])
            fcps = float(data[1])
            goal = float(data[2])
            while ((goal/cps)>(price/cps+goal/(cps+fcps))): # buy new farm
                time += price/cps
                cps += fcps
            time += goal/cps
            print 'Case #'+str(a+1)+': '+str(time)


if __name__ == '__main__':
    main()