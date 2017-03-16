
base_production = 2

def time_to_reach_score(score, production_rate):
    return score / production_rate

def solve(factorycost, factoryproduction, targetscore):
    production = base_production
    factory_production_time = 0

    while True:
        expected_time = time_to_reach_score(targetscore, production)
        production_with_extra_factory = production + factoryproduction
        time_to_make_factory = time_to_reach_score(factorycost, production)
        expected_time_after_extra_factory = time_to_reach_score(targetscore, production + factoryproduction)
        expected_time_with_factory = time_to_make_factory + expected_time_after_extra_factory

        if expected_time_with_factory >= expected_time:
            break

        #print(expected_time, expected_time_with_factory)
        #expected_time = expected_time_with_factory

        production += factoryproduction
        factory_production_time += time_to_make_factory
    return factory_production_time + expected_time

def read_one():
    return map(float, input().split())

def main():
    ncases = int(input())
    for i in range(1, ncases + 1):
        print('Case #{}: {}'.format(i, solve(*read_one())))

main()
