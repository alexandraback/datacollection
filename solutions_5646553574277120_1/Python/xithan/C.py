#!/usr/local/bin/python3
# Codejam ID 4244486
# Run with parameter
# -s for small input
# -l for large input



from GCJ import GCJ

def parse(infile):
    C,D,V = GCJ.readints(infile)
    coins = GCJ.readintarray(infile)
    return C,D,V,coins

def solve(data):
    C,D,V,coins = data
    res = 0
    def calc(cur_max, next_coin, new_coins):
      while cur_max < next_coin-1:
        new_coins += 1
        cur_max += C*(cur_max+1)
        if cur_max >= V:
          return (cur_max, new_coins)

      return (cur_max+next_coin*C, new_coins)

    cur_max = 0
    index = 0
    while cur_max < V and index < len(coins):
      cur_max, res = calc(cur_max,coins[index], res)
      index+=1

    while cur_max < V:
      res += 1
      cur_max += C*(cur_max+1)

    return res


GCJ('C', solve, parse, None).run()

