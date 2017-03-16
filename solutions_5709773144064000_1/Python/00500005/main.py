#!/usr/bin/python3
from googlejam.tools import *

# how long will it take to get to the goal with given income, and wealth?
def simulate(income, goal, time=0, wealth=0):
  return time + ((goal - wealth) / income)

# we can make a generator that just assumes we only buy farms
def simulation(farmcost,farmincome, farms = 0, time = 0, max_time=None):
  BASE_INCOME = 2.0
  while max_time == None or max_time > time:
    income = BASE_INCOME + farmincome * farms
    tick = simulate(income, farmcost)
    yield farms, income, time
    time += tick
    farms += 1
  

class Jam:
  split = " "
  cases = line_cases(("C","F","X"))
  def solve(F,X,C):
    farmincome,wincost,farmcost = map(lambda x:float(x[0]),[F,X,C])
    best_time = float("+inf")
    for farms,income,time in simulation(farmcost,farmincome):
      time_to_win = simulate(income, wincost, time)
      time_to_next_farm = simulate(income, wincost, time)
      time_to_recover_cost = simulate(farmincome, farmcost, time)
      best_time = min(time_to_win,best_time)
      if time_to_win < time_to_recover_cost or time_to_win < time_to_next_farm:
        return "{:.7f}".format(best_time)
import googlejam.main
