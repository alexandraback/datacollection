#!/usr/bin/env python3
# encoding: utf-8
"""
A.py

Created by Alice Lieutier on 2012-05-05.
Copyright (c) 2012
"""

import sys


def process(input, output):
  nb = int(input.readline().rstrip())
  
  for val in range(1, nb+1):
    
    print("Case ",val)
    
    # reading data
    inputs = input.readline().rstrip().split()
    
    nb_contestants = int(inputs[0])
    points = list(map(int,inputs[1:]))    
    X = sum(points)
    
    answers = list()
    nb_pos = nb_contestants
    neg = 0 
    
    for i in range(len(points)):
      r = 2 / len(points) - points[i] / X
      if r < 0:
        neg += r
        nb_pos -= 1
        points[i] = -1
     
    for p in points:
      if p == -1:
        answers.append(0)
        continue
      r = (2 / len(points) - p / X + neg / nb_pos) * 100
      answers.append(r)
    
    answer = ""
    for i in answers:
      answer += " "+str(round(i,6))

    output.write('Case #%d:%s\n' % (val,answer))
    

if __name__ == "__main__":
  if len(sys.argv) != 2:
    print("Need file as argument")
    sys.exit(1)

  input_file = sys.argv[1]

  # open the file
  input_handler = open(input_file, 'r')
  output_handler = open(input_file + '.out', 'w+')

  process(input_handler, output_handler)

  # close files
  input_handler.close()
  output_handler.close()
