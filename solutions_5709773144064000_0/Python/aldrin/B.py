import sys


def main():

    # Open input file and read number of testcases
    f = open(sys.argv[1], 'r')
    testcases = int(f.readline())

    for i in range(1, testcases+1):
        # Read C, F, X
        line = f.readline()
        line = line.rstrip().split(' ')
        Cookie_farm_cost = float(line[0])
        Farm_production = float(line[1])
        X = float(line[2])

        time = 0.0
        cps = 2.0
        # while time to get X is more than time to buy farm and then get X
        while X / cps > (Cookie_farm_cost / cps + X /(cps + Farm_production)):
            # Buy farm
            time += Cookie_farm_cost / cps
            cps += Farm_production
        time += X / cps
        
        print "Case #" + str(i) + ": " + '%.7f' % time



main()