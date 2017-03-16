def energy(initial, regain, events):
    regain = min(regain, initial)
    market = []
    max_gain = 0

    # We need to spend regain each turn
    for event in events[:-1]:
        market.append((event, initial))
        market.sort()
        to_spend = regain

        while to_spend > 0 and len(market) > 0:
            event, max_spending = market.pop()
            spent = min(to_spend, max_spending)
            to_spend -= spent
            max_gain += spent * event
            if max_spending - spent > 0:
                market.append((event, max_spending - spent))
            # print 'Spent %d on (%d, %d). Market: %r' % (spent, event, max_spending, market)

    # After taking care of regain, we can make sure to spend our
    # energy however we like
    market.append((events[-1], initial))
    market.sort()
    to_spend = initial
    while to_spend > 0 and len(market) > 0:
        event, max_spending = market.pop()
        spent = min(to_spend, max_spending)
        to_spend -= spent
        max_gain += spent * event
        # print 'Spent %d on (%d, %d). Market: %r' % (spent, event, max_spending, market)

    return max_gain





def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        pattern = []
        initial, regain, n = read_numbers(sys.stdin.readline())
        events = read_numbers(sys.stdin.readline())
        print "Case #%d: %d" % (i, energy(initial, regain, events))
