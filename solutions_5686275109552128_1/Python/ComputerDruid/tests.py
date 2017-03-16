#!/usr/bin/env python3
import unittest
from B import num_steps

class NumStepsTestCases(unittest.TestCase):
    def test_3way_split(self):
        self.assertEqual(5, num_steps([9]))

    def test_split_small(self):
        self.assertEqual(3, num_steps([3]))
        self.assertEqual(2, num_steps([2,1]))
        self.assertEqual(2, num_steps([2]))

    def test_split_even(self):
        self.assertEqual(3, num_steps([4]))
        self.assertEqual(4, num_steps([6]))
    
    def test_sample(self):
        self.assertEqual(3, num_steps([3]))
        self.assertEqual(2, num_steps([1,2,1,2]))
        self.assertEqual(3, num_steps([4]))

    def test_onlysplitone(self):
        self.assertEqual(4, num_steps([3,6]))

if __name__ == '__main__':
    unittest.main()
