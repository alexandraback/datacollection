'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
import os
from decimal import Decimal
if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)
    sys.argv.remove("--debug")

def main():
    problem_input = sys.stdin
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
        if os.path.isfile(input_file):
            problem_input = open(input_file)
        
    cases = int(problem_input.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case(problem_input)
        print "Case #%s: %s" % (case + 1, resp,)

def run_case(problem_input):
    global cookies, total_time
    farm_cost, farm_rate, goal = (float(x) for x in problem_input.readline().split())
    farm_pay_time = farm_cost / farm_rate
    total_time = 0
    cookies = 0
    rate = 2
    
    
    max_rate = (goal - farm_cost) / farm_pay_time
    farm_goal = max(0, int(1 + (max_rate - rate) / farm_rate))
    
    rates = [rate + x * farm_rate for x in xrange(farm_goal)]
    times = [farm_cost / r for r in rates]
    total_time = sum(times) + goal / (rate + farm_goal * farm_rate)
    
    logging.debug(farm_pay_time)
    logging.debug(max_rate)
    logging.debug(farm_goal)
    #logging.debug(rates)
    #logging.debug(times)
    
    return total_time


def run_case_small(problem_input):
    global cookies, total_time
    farm_cost, farm_value, goal = (Decimal(x) for x in problem_input.readline().split())
    farm_pay_time = farm_cost / farm_value
    total_time = Decimal(0)
    cookies = Decimal(0)
    rate = Decimal(2)
    
    def simulate(length):
        logging.debug("Simulating %s", length)
        global cookies, total_time
        cookies += length * rate
        total_time += length
        
    while True:
        if cookies >= goal:
            #Finished
            break
        
        time_to_goal = (goal - cookies) / rate
        time_to_farm = max(0, (farm_cost - cookies) / rate)
        can_buy_farm = cookies >= farm_cost
        
        logging.debug("%s:%s,%s" %(total_time, cookies, locals(),))
        
        if can_buy_farm:
            logging.debug("Considering buying farm...")
            if time_to_goal >= farm_pay_time:
                logging.debug("Makes sense, buy farm.")
                cookies -= farm_cost
                rate += farm_value
            else:
                logging.debug("No makes sense, rush to goal.")
                simulate(time_to_goal)
        else:
            logging.debug("Can't do anything, wait until something interesting happens")
            simulate(min(time_to_goal, time_to_farm))
        
    return total_time
    

if __name__ == "__main__":
    main()