#!/usr/bin/python

import sys
import itertools
import math

import puzutils

class TrainCars_2014_1CB(puzutils.CodeJamProblem):
  def __init__(self, inputFilename):
    puzutils.CodeJamProblem.__init__(self, inputFilename)

    self.T = None

  def load(self):
    """
      input:

      T (number of test cases)

      N
      aa bb cc (cars)

    """

    self.tests = []

    with open(self.inputFilename, "rt") as file:
      self.T = int(file.readline().strip())

      for i in xrange(self.T):
        n = int(file.readline().strip())
        cars = file.readline().strip().split(' ')
        test = cars

        self.tests.append(test)

    return True

  def validateAllCars(self, cars):
    for car in cars:
      # A car is just a small train
      if not self.validateTrain(car):
        return False

    return True

  def validateTrain(self, train):
    """
      A train is invalid if it contains duplicate letters
      that are non-adjacent.
    """
    i = 0
    while i < len(train):
      c = train[i]

      while train[i] == c:
        i = i + 1
        if i >= len(train):
          return True

      if c in train[i + 1:]:
        return False

    return True

  def compressCar(self, car):
    return ''.join(ch for ch, _ in itertools.groupby(car))

  def compressAll(self, cars):
    newcars = []

    for c in cars:
      c = self.compressCar(c)
      newcars.append(c)

    return newcars

  def combineAll(self, cars):
    while True:
      (cars, changed) = self.combineCars(cars)

      if not changed:
        return cars

  def combineCars(self, cars):
    """
      Find cars that can only be combined in one way and
      return them as a single car.
    """

    changed = False
    newcars = []

    while (len(cars) > 0):
      c = cars[0]
      cars = cars[1:]
      found = False

      for car in cars:
        if (c[-1] == car[0]) and (c[0] == car[-1]):
          # Could be done in any order
          self.multiplier = self.multiplier * 2
          newcars.append(c)
          cars.remove(car)
          changed = True
          found = True
          break
        elif (c[-1] == car[0]):
          # end to front
          nc = c + car
          newcars.append(nc)
          cars.remove(car)
          changed = True
          found = True
          break
        elif (c[0] == car[-1]):
          # front to end
          nc = car + c
          newcars.append(nc)
          cars.remove(car)
          changed = True
          found = True
          break

      if not found:
        newcars.append(c)

    return (newcars, changed)

  def buildConnectedSets(self, cars):
    """
      Return sets of cars that
    """

  def executeTest(self, test):
    """
      Run a test and return output.
    """

    #print test

    if not self.validateAllCars(test):
      return "0"

    self.multiplier = 1

    cars = test
    cars = self.compressAll(cars)

    # Make sure a letter isn't in the middle of a car
    for c in cars:
      for k in cars:
        if (c[0] in k[1:-1]) or (c[-1] in k[1:-1]):
          return "0"

    cars = [c[0] + c[-1] for c in cars]
    cars = self.combineAll(cars)
    cars = self.compressAll(cars)

    print "%d * %s" % (self.multiplier, cars)

    return (math.factorial(len(cars)) * self.multiplier) % 1000000007

    c = 0

    for i in itertools.permutations(cars):
      train = "".join(i)
      train = self.compressCar(train)
      if self.validateTrain(train):
        c = c + 1

    c = c * self.multiplier

    return c % 1000000007

with TrainCars_2014_1CB(sys.argv[1]) as problem:
  problem.load()

  problem.run()
