package com.company;

public class Attack {
    public Attack(int index, int strength) {
        this.index = index;
        this.strength = strength;
    }

    private int index;
    private int strength;

    public int getStrength() {
        return strength;
    }

    public int getIndex()
    {
        return index;
    }
}
