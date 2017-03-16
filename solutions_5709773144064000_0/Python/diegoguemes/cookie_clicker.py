import sys

def cookie_clicker(C, F, X):
    time = 0
    production = 2
    while True:
        time_to_finish = X / production
        time_to_buy_farm = C / production
        production_with_farm = production + F
        time_to_finish_with_farm = X / production_with_farm
        if time_to_finish <= time_to_buy_farm + time_to_finish_with_farm:
            return time + time_to_finish
        time += time_to_buy_farm
        production = production_with_farm

T = int(sys.stdin.readline())
for t in range(1, T + 1):
    answers = []
    arrangements = []
    C, F, X = [float(x) for x in sys.stdin.readline().split()]
    print('Case #{0}: {1:.7f}'.format(t, cookie_clicker(C, F, X)))