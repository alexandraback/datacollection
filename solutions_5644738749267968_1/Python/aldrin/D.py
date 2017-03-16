import sys


def main():

    # Open input file and read number of testcases
    f = open(sys.argv[1], 'r')
    testcases = int(f.readline())

    for i in range(1, testcases+1):
        # Read N
        N = int(f.readline())

        # Get naomi's block weights
        line = f.readline()
        naomi = line.rstrip().split(' ')
        naomi = [float(x) for x in naomi]

        # Get ken's block weights
        line = f.readline()
        ken = line.rstrip().split(' ')
        ken = [float(x) for x in ken]

        deceitful_score = deceitful_war(list(naomi), list(ken))
        war_score = war(list(naomi), list(ken))

        print "Case #" + str(i) + ": " + str(deceitful_score) + " " + str(war_score)

def deceitful_war(naomi, ken):
    points = 0
    # naomi in ascending order, ken in descending order
    naomi.sort()
    ken.sort()
    ken.reverse()

    for k in ken:
        if all(k > n for n in naomi):
            # Naomi can't beat ken, plays smallest block
            naomi.pop(0)
        else:
            # Naomi can beat, plays smallest one larger than k
            temp_naomi = naomi
            for n in temp_naomi:
                # find smallest one larger, remove it, add point
                if n > k:
                    naomi.remove(n)
                    points += 1
                    break
    return points


def war(naomi, ken):
    points = 0

    naomi.sort()
    naomi.reverse()
    ken.sort()

    for n in naomi:
        if all(n > k for k in ken):
            # Naomi's block is more than all of ken's blocks
            ken.pop(0)
            points += 1

        else:
            # Ken can beat naomi, plays smallest one larger than n
            temp_ken = ken
            for k in temp_ken:
                if k > n:
                    ken.remove(k)
                    break

    return points



main()