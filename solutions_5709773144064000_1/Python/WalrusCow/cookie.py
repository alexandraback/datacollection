import sys

# Base cookies per second
BASE_INCOME = 2.0

def findTime():
    '''
    Find the best time to beat this game.o
    Idea: Compare time to win vs time to next farm + win, and iterate.

    Note that it is *never* better to wait to buy a farm - if we are
    buying one, we should buy it ASAP, which resets our cookie count to 0.
    This simplifies things :)
    '''

    farmCost, farmIncome, goal = map(float, sys.stdin.readline().split())

    # Base time and income
    time = 0
    income = BASE_INCOME

    while True:
        # Calculate the time to win if we do nothing
        ttw = goal / income
        # Time until next farm
        ttf = farmCost / income
        # Time to win with next farm income as well
        ttwf = ttf + goal / (income + farmIncome)

        # If the next farm would not speed things up then quit now
        if ttw < ttwf:
            return time + ttw

        # Restart with next income level
        time += ttf
        income += farmIncome

def main(n):
    ''' Read and perform n test cases. '''

    for i in range(n):
        answer = findTime()
        print('Case #{0}: {1:.7f}'.format(i+1, answer))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
